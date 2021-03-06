#include<linux/init.h>
#include<linux/module.h>
#include <linux/fs.h>
#include<linux/kernel.h>
#include<linux/slab.h>
#include <linux/uaccess.h>

MODULE_LICENSE("Dual BSD/GPL");

/* Declaration of memory.c functions */

int memory_open(struct inode *inode, struct file *filp);
int memory_release(struct inode *inode, struct file *filp);
ssize_t memory_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
ssize_t memory_write(struct file *filp, char *buf, size_t count, loff_t *f_pos);
void memory_exit(void);
int memory_init(void);


struct file_operations memory_fops = 
{
	read: memory_read,
	write: memory_write,
	open: memory_open,
	release: memory_release
};

module_init(memory_init);
module_exit(memory_exit);

int memory_major = 60;
char *memory_buffer;


int __init memory_init(void) 
{
	int result;

	/* Registering device */
	result = register_chrdev(memory_major, "memory", &memory_fops);
	if (result < 0) 
	{
		printk(KERN_INFO "cannot obtain major number %d\n", memory_major);
	 	return result;
	}

	/* Allocating memory for the buffer */
	memory_buffer = kmalloc(1, GFP_KERNEL);
	if(!memory_buffer)
	{
		result = -ENOMEM;
		goto fail;
	}
	memset(memory_buffer, 0, 1);
	printk(KERN_INFO "Inserting memory module\n");
	return 0;
	fail: memory_exit();
	return result;
}

void __exit memory_exit(void)
{
	/* Freeing major number */
	
	unregister_chrdev(memory_major, "memory");

	/* Freeing buffer memory */
	
	if(memory_buffer)
	{
		kfree(memory_buffer);
	}
	printk(KERN_INFO "Removing memory module\n");
}

int memory_open(struct inode *inode, struct file *filp)
{
	return 0;
}

int memory_release(struct inode *inode, struct file *filp)
{
	return 0;
}

ssize_t memory_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	/* Transfering data to user space */
	copy_to_user(buf, memory_buffer, 1);
	/* Changing reading position as best suits */
	if(*f_pos == 0)
	{
		*f_pos += 1;
		return 1;
	}
	else
		return 0;
}

ssize_t memory_write(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	char *tmp;
	tmp = buf + count - 1;
	copy_from_user(memory_buffer, tmp, 1);
	return 1;
}





