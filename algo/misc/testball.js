
var calSum = function(val)
{
    let sum = 0;
    while(val >= 10){
        sum += (val % 10);
        val = Math.floor(val /10);
    }

    sum += val;
    return sum;
};

var countBalls = function(lowLimit, highLimit) { 
    let max_count = 0;
    let cur_count = 0;
    
    let sum = 0;
    let ball_counts = {};
    for(index = lowLimit; index <= highLimit; ++index){
        sum = calSum(index);
        if(ball_counts[sum] === undefined){
            ball_counts[sum] = 1;
            cur_count = 1;
        }
        else{                
            ball_counts[sum] += 1;
            cur_count = ball_counts[sum];
        }

        if(cur_count > max_count){
            max_count = cur_count;
        }
    }
    return max_count;
};

console.log(countBalls(5, 15));
