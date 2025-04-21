class Queue{
  constructor(){
    this.queue = [];
    this.front = -1;
    this.rear = -1;
    this.qSize = 5;
  }

  isFull(){

  }

  isEmpty(){

  }

  enqueue(data){
    if(this.front == -1 && this.rear == -1){
      this.front = this.rear = 0;
      this.queue[this.rear] = data;
    }else if(this.qSize == this.rear + 1){
      console.log('**Queue Full**');
    }else{
      this.rear++;
      this.queue[this.rear] = data;
    }
  }

  dequeue(){
    if(this.front == -1 && this.rear == -1){
      console.log('**Queue Empty**');
    }else if(this.front == this.rear){
      console.log('Dequeue = ', this.queue[this.front]);
      this.front = this.rear = -1;
    }else{
      console.log('Dequeue = ', this.queue[this.front]);
      this.front++;
    }
  }

  peek(){

  }
   
  display(){
    
  }

}




let Q = new Queue();
console.log('**============Start==============**');
Q.enqueue(10);
Q.enqueue(20);
Q.enqueue(60); // Overflow

Q.dequeue();
Q.dequeue();
Q.dequeue();
Q.enqueue(30);
Q.enqueue(40);
Q.enqueue(50);
// Q.dequeue();
// Q.dequeue();
// Q.dequeue();
// Q.dequeue();
console.log('**=============End==============**');
console.log(Q);