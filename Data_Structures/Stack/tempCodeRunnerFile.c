for (int i = 0; i < s->q.rear - s->q.front; i++)
    {
        enqueue(&s->q, dequeue(&s->q));
    }