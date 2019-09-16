var num = read_line();
var temp = read_line().split(" ");
//
var str = [];
for(var i = 1;i<=num;i++){
    str.push(i);
}
//console.log(str);
//console.log(temp);
//
var countAll = 0;
var countCan = 0;
function arrange(s){
    for(var i =0,length=str.length;i<length;i++){
        if(s.length == length-1){
            if(s.indexOf(str[i])<0){
                countAll++;
                var newStr = s+str[i];
                // console.log(newStr);
                //strat:
                for(var j = 0;j<temp.length;j++){
                    if(temp[j]==0){
                        if(newStr[j]<newStr[j+1]){

                        }else{
                            break;
                        }
                    }
                    if(temp[j]==1){
                        if(newStr[j]>newStr[j+1]){

                        }else{
                            break;
                        }
                    }
                    if(j==temp.length-1){
                        countCan++;
                    }
                }
                //end
            }
            continue;
        }
        if(s.indexOf(str[i])<0){
            arrange(s+str[i]);
        }
    }
}
arrange("");
console.log(countCan%(Math.pow(10,9)+7));