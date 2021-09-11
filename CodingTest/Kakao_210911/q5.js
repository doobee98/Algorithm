class Node {
  constructor(id, value) {
    this.id = id;
    this.value = value;
    this.childs = [];
  }

  addChild(id) {
    this.childs.push(id);
  }
}

class Tree {
  constructor(info, edges) {
    this.nodes = info.map((value, idx) => new Node(idx, value));
    for (let [from, to] of edges) {
      this.nodes[from].addChild(to);
    }
  }

  getNode(id) {
    return this.nodes[id];
  }
}

function solution(info, edges) {
  const tree = new Tree(info, edges);

  const getChoices = (visited) => {
    let choiceSet = new Set();

    for (let id of visited) {
      const node = tree.getNode(id);
      for (let childId of node.childs) {
        choiceSet.add(childId);
      }
    }

    for (let id of visited) {
      choiceSet.delete(id);
    }

    return Array.from(choiceSet);
  };

  const solve = (path, life) => {
    const choices = getChoices(path);

    if (choices.length === 0 || life < 1) {
      const shipNodes = path.filter((id) => tree.getNode(id).value === 0);
      return shipNodes.length;
    }

    // 먼저 양은 전부 다 path에 넣기 (greedy)
    const shipChoices = choices.filter((id) => tree.getNode(id).value === 0);
    if (shipChoices.length > 0) {
      return solve(path.concat(shipChoices), life + shipChoices.length);
    }

    // 후보가 전부 다 늑대라면 하나하나 경우의수 돌아보기
    const result = choices.map((choice) => solve([...path, choice], life - 1));
    return Math.max(...result);
  };

  return solve([0], 1);
}
