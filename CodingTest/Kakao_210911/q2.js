function isPrime(n) {
  if (n < 2) return false;

  let n_sqrt = Math.sqrt(n);
  for (let i = 2; i <= n_sqrt; i++) {
    if (n % i === 0) return false;
  }

  return true;
}

function solution(n, k) {
  let n_string = n.toString(k);
  let splited_list = n_string
    .split("0")
    .filter((item) => item !== "")
    .map((item) => parseInt(item));
  let prime_list = splited_list.filter((m) => isPrime(m));
  let prime_count = prime_list.length;
  return prime_count;
}
