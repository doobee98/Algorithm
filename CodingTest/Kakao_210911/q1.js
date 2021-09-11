function solution(id_list, report, k) {
  let report_who = {};
  let reported_count = {};

  // initialize
  for (let id of id_list) {
    report_who[id] = new Set();
    reported_count[id] = 0;
  }

  let add_report = (from, to) => {
    if (report_who[from].has(to)) return;

    report_who[from].add(to);
    reported_count[to] += 1;
  };

  // report 등록
  for (let report_item of report) {
    let [from, to] = report_item.split(" ");
    add_report(from, to);
  }

  // 신고횟수 정리
  let banned_id_list = id_list.filter((id) => reported_count[id] >= k);

  // 메일 받는 횟수 정리
  let banned_mail_count_list = id_list.map((id) => {
    let report_who_list = Array.from(report_who[id]);
    let banned_mail_who_list = report_who_list.filter((report_id) =>
      banned_id_list.includes(report_id)
    );
    return banned_mail_who_list.length;
  });

  return banned_mail_count_list;
}
