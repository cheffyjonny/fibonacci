const readline = require('readline')

class FibonacciCounter {
  constructor() {
    this.count0 = 0
    this.count1 = 0
  }

  fibonacci(n) {
    if (n === 0) {
      this.count0++
      return 0
    } else if (n === 1) {
      this.count1++
      return 1
    } else {
      return this.fibonacci(n - 1) + this.fibonacci(n - 2)
    }
  }
}

function generateRandomNum() {
  // min, max value could be converted into parameters to make the function generic.
  const min = 0
  const max = 40
  return Math.floor(Math.random() * (max - min) + min)
}

// Get count how many times 0 and 1 are called.
function getFibonacciCounts(n) {
  const counter = new FibonacciCounter()
  counter.fibonacci(n)
  return { count0: counter.count0, count1: counter.count1 }
}

// 'i' is not utilized as it solely displays counts.
function printFibonacciCounts(i) {
  const randomNum = generateRandomNum()
  const result = getFibonacciCounts(randomNum)

  // 과제 출력 요청되로 출력되는 횟수를 공백으로 구분하여서 출력하였습니다. 좀더 구체적인 정보를 입력한 방법도 구현해 보았습니다(line 44-46)
  console.log(`${result.count0} ${result.count1}`)

  //   console.log(
  //     `Result for round ${i} = ${randomNum} (count0 : ${result.count0} & count1 : ${result.count1})`
  //   )
}

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

rl.question('Enter the number of iterations: ', (numIterations) => {
  rl.close()

  numIterations = parseInt(numIterations)

  if (isNaN(numIterations) || numIterations <= 0) {
    console.error('Please enter a valid positive number of iterations.')
    return
  }

  for (let i = 1; i <= numIterations; i++) {
    printFibonacciCounts(i)
  }
})
