const x = [1,3,4,3]
const y = [3,4,7]

function commonValues (arr1, arr2) {
    let matchingValues = [];
    let filteredArr1 = filterArrayToUniqueValues(arr1);
    let filteredArr2 = filterArrayToUniqueValues(arr2);

    for (let i = 0; i < filteredArr1.length; i++) {
        for (let y = 0; y < filteredArr2.length; y++) {
            if(filteredArr1[i] === filteredArr2[y]) {
                matchingValues.push(filteredArr2[y]);
            }
        }
    }

    return matchingValues;
}

function filterArrayToUniqueValues(arr) {
    let filteredArray = [];
    for (let i = 0; i< arr.length; i++) {
        if(!(filteredArray.indexOf(arr[i]) >= 0)) {
            filteredArray.push(arr[i]);
        }
    }
    return filteredArray;
}


//console.log(commonValues(x, y));

function fibonacciValueAtPosition(num) {    
    /*1 1 2 3 5 8*/
    if ( num <= 1) return 1;

    return fibonacciValueAtPosition( num - 1) + fibonacciValueAtPosition(num - 2)
}

function improvedFibonacci(num, hashMemory) {    
    /*1 1 2 3 5 8*/
    hashMemory = hashMemory || {};
    if(hashMemory[num]) return hashMemory[num];
    if ( num <= 1) return 1;

    return hashMemory[num] = improvedFibonacci( num - 1, hashMemory) + improvedFibonacci(num - 2, hashMemory)
}

console.log(fibonacciValueAtPosition(1));
console.log(fibonacciValueAtPosition(2));
console.log(fibonacciValueAtPosition(3));

// console.log(fibonacciValueAtPosition(40));
console.log(improvedFibonacci(55));
