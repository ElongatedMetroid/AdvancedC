/*allows more optimized code for variables that are not used much
but have to be edited at one point in the programs runtime*/
int i;

i = 10;

/*some code not using i*/

i = 30;

//above is something you would want to use the volitile keyword for

volatile int ii;

ii = 10;

/*some code no using ii*/

ii = 30;

const volatile int i;