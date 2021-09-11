function solution(board, skill) {
  const N = board.length;
  const M = board[0].length;

  const serialized_index = (r, c) => r * M + c;

  const serialize_all_skills = (skills) => {
    let damage_list = new Array(N * M).fill(0);

    for (const skill of skills) {
      const [type, r1, c1, r2, c2, degree] = skill;

      for (let r = r1; r <= r2; r++) {
        for (let c = c1; c <= c2; c++) {
          const idx = serialized_index(r, c);
          damage_list[idx] += type === 1 ? degree : -degree;
        }
      }
    }

    return damage_list;
  };

  const damage_list = serialize_all_skills(skill);
  let undestructed_sum = 0;

  for (let r = 0; r < N; r++) {
    for (let c = 0; c < M; c++) {
      const health = board[r][c];
      const damage = damage_list[serialized_index(r, c)];

      if (health - damage >= 1) undestructed_sum++;
    }
  }
  return undestructed_sum;
}
