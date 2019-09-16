var line = '1 2 3 4 5 #';
var num = '3';
num = parseInt(num);
var arr = line.split(" ");
arr.pop();
// console.log(arr);

var result = [];
var num2 = parseInt(arr.length/num);
for (let i = 0; i < num2; i++) {
    // console.log(i);
    for (let index = (num-1); index >= 0; index--) {
        result.push(arr[index]);
        arr.splice(index,1);    
    }
}
if(arr.length>=1){
    result = result.concat(arr);
}
// console.log(result);
var out = '';
for (let index = 0; index < result.length; index++) {
    if(index==result.length-1){
        out+=result[index];
    }else{
        out+=result[index]+'->';
    }  
}
console.log(out);