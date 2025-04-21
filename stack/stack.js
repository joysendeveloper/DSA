class Stack {
    top = 0;
    data = [];

    push(data){
        this.data[this.top] = data;
        this.top++;
    }

    pop(){
        if(this.top == 0) return;

        this.top--;
        return this.data[this.top];
    }
}


const bracketMatcher = sequence => {
    let s1 = new Stack();
    let length = sequence.length;
    
    for(let i = 0; i < length; i++){
        if(sequence[i] == '(' || sequence[i] == '{' || sequence[i] == '[') 
        s1.push(sequence[i]);
        else if(sequence[i] == ')' && s1.pop() != '(') return 'NO';
        else if(sequence[i] == '}' && s1.pop() != '{') return 'NO';
        else if(sequence[i] == ']' && s1.pop() != '[') return 'NO';
    }

    return s1.top == 0 ? 'YES' : 'NO';

}

let sequence = '(([]{}[{}]){})[]';
// let sequence = prompt();
console.log(bracketMatcher(sequence));
