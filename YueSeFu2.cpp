/*约瑟夫问题是一个著名的趣题。这里我们稍稍修改一下规则。有n个人站成一列。并从头到尾给他们编号，第一个人编号为1。然后从头开始报数，第一轮依次报1，2，1，2...然后报到2的人出局。接着第二轮再从上一轮最后一个报数的人开始依次报1，2，3，1，2，3...报到2，3的人出局。以此类推直到剩下以后一个人。现在需要求的即是这个人的编号。
给定一个int n，代表游戏的人数。请返回最后一个人的编号
测试样例：
5
返回：5
*/

class Joseph {
public:
    int getResult(int n) {
        // write code here
        

        vector<int >s;
        vector<int >d;
        int ci=2;
        
        for(int i=0;i<n;i++)
            {
            	d.push_back(i);
            }
        
        int size = d.size();
        while(size > 1)
            {
            s.clear();
            for(int i=0;i<d.size();i++)
            {
                if(i%ci == 0)
                    {
                    s.push_back(d[i]);
                }
            }
            ci++;
            size = s.size();
            d.clear();
            d.push_back(s[size-1]);
            d.insert(d.begin()+1,s.begin(),s.end()-1);
        }
        return s[0]+1;
    }
};
