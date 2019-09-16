let string = '2019-01-09'

var Jan = new Date(string)
Jan.setMonth(0);
Jan.setDate(1);
//console.log(Jan);

var line = new Date(string)
//console.log(line);

var result = (line-Jan)/1000/60/60/24;
console.log(result+1);