//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
 
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
using namespace std;
 
typedef double numeric;
typedef std::vector<numeric> numeric_vector;
 
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
numeric total_variance(numeric_vector &v)
{
  numeric n = 0.0;
 
  if (v.size() < 2) return 0;
 
  numeric_vector::iterator i = v.begin();
 
  numeric last = *i;
 
  for (++i; i != v.end(); ++i)
  {
    n += abs(last - *i);
    last = *i;
  }
 
  return n;
}
 
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
numeric_vector populate()
{
  numeric_vector values;
  values.push_back(0.75);
  values.push_back(0.50);
  values.push_back(0.80);
  values.push_back(0.85);
 
  return values;
}
 
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void output_variance_vector(numeric_vector &v)
{
  cout << "variance vector: " << endl;
  for (numeric_vector::iterator i = v.begin(); i != v.end(); ++i)
  {
    cout << "\t" << *i << endl;
  }
  cout << endl;
}
 
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
numeric average_variance(numeric_vector &v)
{
  return total_variance(v) / (v.size() - 1);
}
 
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
numeric variance(numeric_vector &v, numeric first, numeric second)
{
  return abs(v[first] - v[second]); 
}
 
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void all_variance(numeric_vector &v)
{
  for (int i = 1; i < v.size(); ++i)
  {
    std::cout << "variance: [" << i-1 << ", " << i << "]: ";
    std::cout << variance(v, i-1, i) << endl;
   
    //if (variance(v, i-1, i) < average_variance(v) / 2)
    if (variance(v, i-1, i) < average_variance(v) / 4) //mejbah added
    {
      cout << "stopping point -- " << i << endl;
    }
  }
}
 
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main()
{
  numeric_vector val(100);
  val = { 11.34988367 ,
11.06320207	,
7.781781676	,
10.793208 ,
10.92818585	,
10.52165284	,
9.877682368	,
8.320128778	,
8.615151541	,
6.9293011 ,
9.262941956	,
9.094674527	,
7.072988365	,
10.25394316	,
10.39371293	,
9.996908252	,
9.503501702	,
8.102455755	,
8.199460749	,
6.805023068	,
8.791527891	,
8.807128798	,
6.869004983	,
10.12493655	,
10.2639996	,
9.847703326	,
9.29531499	,
7.994151955	,
8.028009866	,
6.784730591	,
10.19100103	,
10.14225566	,
10.10592042	,
10.07378247	,
9.753698316	,
9.707867372	,
9.201688878	,
9.177826577	,
8.584932106	,
8.552625428	,
8.498517916	,
8.462788681	,
7.969961015	,
7.937836792	,
7.923294108	,
7.859156696	,
6.804615277	,
6.770273724	,
6.76632949	,
6.755495684	,
7.859156696	,
6.804615277	,
6.770273724	,
6.76632949	,
6.755495684	,
6.755495684	,
6.804615277	,
6.770273724	,
6.76632949	,
6.755495684	,
7.923294108	,
7.969961015	,
7.937836792	,
6.76632949	,
7.859156696	,
8.462788681	,
7.923294108	,
7.969961015	,
7.937836792	,
6.76632949	,
7.859156696	,
7.923294108	,
7.969961015	,
7.937836792	,
6.76632949	,
7.859156696	,
6.804615277	,
6.770273724	,
6.76632949	,
6.755495684	,
6.804615277	,
6.770273724	,
6.76632949	,
6.755495684	,
6.755495684	,
6.804615277	,
6.770273724	,
6.76632949	,
6.755495684	,
6.770273724	,
6.76632949	,
6.755495684	,
6.76632949	,
6.755495684	,
6.76632949	,
6.804615277	,
6.804615277	,
6.770273724	,
6.76632949	,
6.755495684	
 };
/*
  val = {5.494342086	,
7.916777797	,
4.159434811	,
7.004219478	,
5.62427343	,
5.926341905	,
6.49779539	,
4.774901815	,
3.588224861	,
6.157592468	,
5.481350689	,
4.114797253	,
5.068479837	,
4.35745786	,
4.519130969	,
5.732816867	,
5.200115176	,
4.981531033	,
2.594573407	,
2.387858834	,
2.036633385	,
1.697726183	,
1.511308355	,
1.842889835	,
3.082777955	,
3.199159748	,
2.299941582	,
1.935774618	,
1.959128611	,
3.027970536	,
1.878033998	,
2.706700069	,
2.021090086	,
2.159893951	,
2.496028453	,
3.010362558	,
4.726005433	,
2.457526571	,
2.749824235	,
1.564416306	,
2.373237192	,
2.2418826 ,
2.144018418	,
4.314264802	,
2.24189109	,
1.624065079	,
2.172795624	,
2.303880007	,
3.052095211	,
2.484433554	,
2.645050547	,
2.690561078	,
2.730974767	,
2.495623429	,
2.869964669	,
2.368171788	,
2.459259611	,
2.165990824	,
2.833107453	,
2.646853177	,
2.495025712	,
2.07156585	,
2.264518174	,
1.714190106	,
2.317460115	,
3.043185441	,
2.686634352	,
3.205467361	,
2.003859835	,
1.796372085	,
1.890978969	,
2.86891303	,
1.760450856	,
1.875494543	,
1.904661688	,
2.413504031	,
2.213403703	,
2.747534151	,
2.000974289	,
2.441262375	,
2.066781559	,
2.894198557	,
2.292902059	,
3.747110538	,
2.062363572	,
1.86707549	,
3.312664841	,
2.141515481	,
1.609497731	,
2.540575203	,
2.140708126	,
2.698193627	,
1.729686797	,
2.240808145	,
1.942329958	,
1.81948244	,
2.558514149	,
2.073734894	,
2.777844037	,
1.984316542	 } ;
*/
  //numeric_vector val = populate();
  
 
  output_variance_vector(val);
 
  cout << "  total variance: " << total_variance(val) << endl;
  cout << "average variance: " << average_variance(val) << endl;
  cout << endl;
 
  all_variance(val);
 
  return 0;
}