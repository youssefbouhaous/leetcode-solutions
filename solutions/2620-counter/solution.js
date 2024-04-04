/**
 * @param {number} n
 * @return {Function} counter
 */
 
var createCounter = function(n) {
    var a=-1001;
    return function() {
        if(a==-1001){
        a=n-1;
        }
        a++;
        return a;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */