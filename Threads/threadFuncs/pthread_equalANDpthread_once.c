/*

You CANNOT use == to compare two thread ID's, for this you will have to use
pthread_equal(thread1, thread2);

The pthread_once function execute the init_routine exactly once in a process
    The first call to this function by any thread in the process execute the given init_routine without parameters
    Any other calls will have no effect

pthread_once(once_control, init_routine);

*/