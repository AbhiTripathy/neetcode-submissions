class Solution {
public:
    int calPoints(vector<string> &operations)
{
  vector<int> record;
  for (string x : operations)
  {
    if (x == "+")
    {
      record.push_back(record[record.size() - 1] + record[record.size() - 2]);
    }
    else if (x == "D")
    {
      record.push_back(record[record.size() - 1] * 2);
    }
    else if (x == "C")
    {
      record.pop_back();
    }
    else
    {
      record.push_back(stoi(x));
    }
  }
  int sum = 0;
  for (int x : record)
    sum += x;
  return sum;
}
};