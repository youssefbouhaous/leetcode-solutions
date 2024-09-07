/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let ans=[];
    let b=[];
    for(let i=0;i<arr.length;i++){
        if(b.length<size){
            b.push(arr[i]);
        }
        if(b.length==size){
            ans.push(b);
            b=[];
        }
    }
    if(b.length!=0)
    ans.push(b);
    return ans;
};
