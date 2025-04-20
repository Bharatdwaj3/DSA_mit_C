//Circular queue

```C

    void enqueue(int value){
        if((rear+1)%MAX==front){
            printf("Queue is full\n");
        }else{
            if(front==-1) front=0;
            rear=(rea+1)%MAX;
            queue(rear)=value;
            printf("%d enqueued",value);
        }
    }

    int dequeue(){
        if(front==-1){
            printf("Queue is empty\n");
            return -1;
        }else{
            int dequeuedValue =queue[front];
            if(front==rear){
                front=rear=-1;
            }else{
                front=(front+1)%MAX;
            }
            return dequeueValue;
        }
    }

    void display(){
        if(front==-1){
            printf("Queue is empty\n");
        }else{
            int i=front;
            printf("Queue: ");
            while(i!=rear){
                printf("%d",queue[i]);
                i=(i+1)%MAX;
            }
            printf("%d\n",queue[rear]);
        }
    }

```