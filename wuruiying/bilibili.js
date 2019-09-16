let frist = '1+-2i'
let second = '3+4i'

let a1 = frist.split('+')[0]==''?0:frist.split('+')[0];
let b1 = second.split('+')[0]==''?0:second.split('+')[0];

let a2 = frist.split('+')[1].replace('i','')==''?1:frist.split('+')[1].replace('i','');
let b2 = second.split('+')[1].replace('i','')==''?1:second.split('+')[1].replace('i','');

console.log(a1,b1,a2,b2);

let result1 = a1*b1+(-a2*b2);
let result2 = a1*b2+(a2*b1);
result2 = result2.toString()+'i';
console.log(result1+'+'+result2);
