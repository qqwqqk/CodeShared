let sum =1;
const func = n=>n<=2?1:func(n-1) + func(n-2);
sum+= [func(3),func(6)].reduceRight((cur,next)=>('${cur}' + '${next}'))
console.log(sum);

console.log(['10','1010','101010'].map(parseint))

function compare(ss1,ss2){
  if(ss1[0] == ss2[0]){
    if(ss1[1] == ss2[1]){
      return ss1[2] < ss2[2];
    }
    return ss1[1] < ss2[1];
  }
  return ss1[0] < ss2[0];
}

if(compare(ss1,ss2)){
  console.log(s1+','+s2);
} else {
  console.log(s2+','+s1);
}


