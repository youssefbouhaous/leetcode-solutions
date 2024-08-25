/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var c=init;
    return {
        increment : ()=>{ 
            return ++c;
        },
        decrement : ()=>{
            return --c;
        },
        reset : ()=>{
            return c=init;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */