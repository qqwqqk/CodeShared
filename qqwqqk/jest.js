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

var result =0;
function test(result){
  result =1;
}
test(2);

var a={}, b={key:'b'}, c={key:'c'};
a[b] = 'b';
a[c] = 'c';
console.log(a[b]);

JSON.stringify({a:null});

var url="https//www.bilibili.com/text.html";
escape(url);
encodeURI(url);
encodeURIComponent(url);

var a={x:1,y:2};
var b =[1,2];
var c = 1;
var o={a:a,b:b,c:c};
a.x=6;
b[1]=7;
c=8;
console.log(o.a.x, o.b[1], o.c);

var fn = function(a,b){reutrn +a+'b'}();
console.log(typeof fn);

['10','10','10','10','10'].map(parseInt);

const first = ()=>(new Promise((resolve,reject)=>{
  console.log(1);
  let p= new Promise((resolve,reject)=>{
    console.log(2);
    setTimeout(()=>{
      console.log(3);
      resolve(4);
    },0)
    resolve(5);
  });
  resolve(6);
  p.then((arg)=>{
    console.log(arg);
  });
}));

first().then((arg)=>{
  console.log(arg);
});

console.log(7);


var age =100;
let years =6;
if(age >12){
  let age =10;
  var years = age *3;
}

console.log("${years} years");

var name = "global";
var obj = {
  name:"local",
  foo: function(){
    this.name = "foo";
  }.bind(window)
};
var bar = new obj.foo();

setTimeout(function(){
  console.log(window.name);
},0);
console.log(bar.name);
var bar3 = bar2 = bar;
bar2.name = "foo2";
console.log(bar3.name);

let arr = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]];
function inter(arr){
  let cache = [];
  let n=arr.length;
  for(let k=0; k<n/2; k++){
    let i=k;
    let j=k;
    for(; j<n-k; j++){cache.push(arr[i][j]);}
    i++;j--;
    for(; i<n-k; i++){cache.push(arr[i][j]);}
    i--;j--;
    for(; j>=k; j--){cache.push(arr[i][j]);}
    j++;i--;
    for(; i>k; i--){cache.push(arr[i][j]);}
  }
  for(let i=0; i<n*n; i++){
    console.log(cache[i]);
    if(i+1 != n*n){
      console.log(',');
    }
  }
}
inter(arr);

(arr)=>{
  let n=arr.length;
  for(let k=0; k<n; k++){
    let i=k;
    let j=k;
    for(; j<n-k; j++){console.log(arr[i][j]);}
    for(; i<n-k; i++){console.log(arr[i][j]);}
    for(; j>=k; j--){console.log(arr[i][j]);}
    for(; i>k; i--){console.log(arr[i][j]);}
  }
}([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])