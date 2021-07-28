typedef struct Set *Set;
typedef struct Queue *Queue;
typedef struct Graph *Graph;

typedef int Vertex;

Set newSet(int len);
Queue newQueue(void);

void enqueue(Queue q, Vertex v);
Vertex dequeue(Queue q);
int queueLen(Queue q);

void addToSet(Set s, Vertex v);
int setHasElement(Set s, Vertex v);

int graphNumV(Graph g);
int graphAdjacent(Graph g, Vertex from, Vertex to);

// Could you do this recursively?
Set reachable(Graph g, Vertex v) {
    Set seen = newSet(graphNumV(g));

    Queue queue = newQueue();
    enqueue(queue, v);

    while (queueLen(queue) != 0) {
        Vertex v = dequeue(queue);
        if (setHasElement(seen, v)) continue;

        addToSet(seen, v);

        for (Vertex w = 0; w < graphNumV(g); w++) {
            if (graphAdjacent(g, v, w) && !setHasElement(seen, w)) {
                enqueue(queue, w);
            }
        }
    }

    return seen;
}