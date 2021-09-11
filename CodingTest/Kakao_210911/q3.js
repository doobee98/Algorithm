function getMinutes(record_time_string) {
  const [hour, minutes] = record_time_string.split(":");
  return parseInt(hour) * 60 + parseInt(minutes);
}

function solution(fees, records) {
  const [basic_time, basic_fee, unit_time, unit_fee] = fees;

  const calculate_parking_fee = (parking_time) => {
    if (parking_time <= basic_time) return basic_fee;

    const over_time = parking_time - basic_time;
    return basic_fee + Math.ceil(over_time / unit_time) * unit_fee;
  };

  // record 계산
  const in_time_record = {};
  const total_time_record = {};

  for (let record of records) {
    const [record_time_string, car_number, record_type] = record.split(" ");
    const record_time = getMinutes(record_time_string);

    if (record_type === "IN") {
      in_time_record[car_number] = record_time;
    } else if (record_type === "OUT") {
      const in_time = in_time_record[car_number];
      const elasped_time = record_time - in_time;
      total_time_record[car_number] =
        (total_time_record[car_number] || 0) + elasped_time;
      delete in_time_record[car_number];
    } else {
      assert(false);
    }
  }

  // 23:59 출차처리
  const last_time = getMinutes("23:59");
  for (let car_number in in_time_record) {
    const in_time = in_time_record[car_number];
    const elasped_time = last_time - in_time;
    total_time_record[car_number] =
      (total_time_record[car_number] || 0) + elasped_time;
  }

  // 차량번호 배열을 정렬해서 answer 출력
  let car_number_list = Object.keys(total_time_record);
  car_number_list.sort();

  const fee_list = car_number_list.map((car_number) => {
    const total_time = total_time_record[car_number];
    const fee = calculate_parking_fee(total_time);
    return fee;
  });

  return fee_list;
}
