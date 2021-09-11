function solution(n, info) {
  const apeachInfo = info;
  const getCount = (scoreInfo, point) => scoreInfo[10 - point];
  const changeInfo = (scoreInfo, point, newCount) =>
    scoreInfo.map((count, idx) => (idx !== 10 - point ? count : newCount));

  const solve = (currentPoint, remain, currentScoreDiff, currentLionInfo) => {
    // 0점은 쏴도 의미없으니까 여기서 점수 계산
    if (currentPoint === 0) {
      // 남은 화살 전부 0점에 쏘기
      const lionInfo = changeInfo(currentLionInfo, 0, remain);
      return currentScoreDiff > 0 ? [currentScoreDiff, lionInfo] : [-1, [-1]];
    }

    const apeachCount = getCount(apeachInfo, currentPoint);

    // 이번 포인트를 따는 경우 - 남은 화살수가 부족할 경우 계산하지 않고 [-1, [-1]] 반환함
    const [winDiff, winLionInfo] =
      remain < apeachCount + 1
        ? [-1, [-1]]
        : solve(
            currentPoint - 1,
            remain - apeachCount - 1,
            currentScoreDiff + currentPoint,
            changeInfo(currentLionInfo, currentPoint, apeachCount + 1)
          );

    // 이번 포인트를 포기하는 경우 - 둘다 쏘지 않을 경우에는 어피치가 점수를 가져가지 않음
    const [loseDiff, loseLionInfo] =
      apeachCount === 0
        ? solve(currentPoint - 1, remain, currentScoreDiff, currentLionInfo)
        : solve(
            currentPoint - 1,
            remain,
            currentScoreDiff - currentPoint,
            currentLionInfo
          );

    if (winDiff > loseDiff) return [winDiff, winLionInfo];
    if (winDiff < loseDiff) return [loseDiff, loseLionInfo];

    // 점수가 동일한 경우 낮은 점수를 맞춘 것들부터 return
    for (let i = 10; i >= 0; i--) {
      if (winLionInfo[i] > loseLionInfo[i]) return [winDiff, winLionInfo];
      if (winLionInfo[i] < loseLionInfo[i]) return [loseDiff, loseLionInfo];
    }
    return [winDiff, winLionInfo];
  };

  const solveMain = () => solve(10, n, 0, [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]);

  const [diff, lionInfo] = solveMain();
  return lionInfo;
}
