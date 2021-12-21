//the point of making a function inline is to hint to the compiler that it is worth making
//some extra form of effort to call the function faster than it would otherwise

//it is reccomending for only short functions that are called frequently

int main(){

    return 0;
}

inline static void foo(){
    //do something
}