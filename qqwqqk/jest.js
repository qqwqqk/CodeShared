let sum =1;
const func = n=>n<=2?1:func(n-1) + func(n-2);
sum+= [func(3),func(6)].reduceRight((cur,next)=>('${cur}' + '${next}'))
console.log(sum);

console.log(['10','1010','101010'].map(parseint))