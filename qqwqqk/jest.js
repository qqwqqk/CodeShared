let sum =1;
const func = n=>n<=2?1:func(n-1) + func(n-2);
sum+= [func(3),func(6)].reduceRight((cur,next)=>('${cur}' + '${next}'))
console.log(sum);

console.log(['10','1010','101010'].map(parseint))

var str1 = "abc123def456";
var str2 = str1.replace(/\d+/,"*");
console.log(str2);

var website="http://www.cctv.com.cn";
var n = website.indexOf(".");
console.log(n);