struct _coord { // 16
    double x;   // 0
    double y;   // 8
};

typedef struct _node Node;
struct _node { // 8 or 12
    int value;  // 0
    Node *next; // 4 (MIPS) else 8 (C)
};

struct _enrolment {
    int stu_id;         // 0
    char course[9]:     // 4
    char term[5];       // 13
    char grade[2];      // 18
    
    // aligned either 4 or 8 byte boundaries (depending on OS + Compiler)
    // 21 + (3) => % (4 or 8 depending)
    double mark;        // 24
};

struct _queue {
    int nitems;     // # items currently in queue
    int head;       // index of oldest item added
    int tail;       // index of most recent item added
    int maxitems;   // size of array
    Item *items;    // malloc'd array of Items
};