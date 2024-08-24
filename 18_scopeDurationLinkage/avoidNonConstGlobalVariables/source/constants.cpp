static int y = 7;
int x{y};                                // static initalization order fiasco
int g_mutex{};                           // Best practices

int moo(){
    return y;
}

int getMutex(){                          // Best practices
    return g_mutex;
}

void setMutex(int mutex){                // Best practices
    g_mutex = mutex;
}