static float kp=1, ki=0.1, kd=0.01
static float i=0, last=0;

float pid (float set, float meas)
{
    float e = set - meas;
    i += e;
    if( i > 100 )
    {
        i=100;
    }
    if ( i < -100)
    {
        i=-100;
    }

    float d = e - last;
    last = e;
    float  o = kp*e + ki*i + kd*d;
    if( o > 100 )
    {
        o = 100;
    }
    if ( o < 0 )
    {
        o = 0;
    }
    return o;

}