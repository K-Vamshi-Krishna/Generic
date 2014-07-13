class MinimumNumberConferenceRoom
{
  class meeting
	{
		float start;
		float end;
		public 
		
	};
	public static void main()
	{
	
	
	
	
	}	
}

class Meeting
{
	
	int startTime;
	int endTime;
	
	intersect()
}
public class quickUnion{

	
	int id[];
	int sz[];
	
	public quickUnion(int N)
	{
		id =new int[N];
		for(int i=0; i<N; i++)id[i]=i;
		sz = new int [N];
		for( int =0; i < N ; i++) id[i] =1;
	}
	
	private int root(int i)
	{
		while(i != id[i]) i =id[i];
		
		return i;
	}
	public boolean connected(int p, int q)
	{
		return root(p) = root(q);
	}
	public void union(int p,int q)
	{
		int j = root(p);
		int i = root(q);
		if(sz[i] < sz[j]) 
		{
		}
		else
		{
		
		}
	}
	
}

/*
quck union find
connected id[p]= id[q]
union  for id in id.len i id[i] == pid id[i] =q[id]

quick union
connected root(p) ==root(q)
union(p,q) id[p]= root(q)

weighted union

union(p,q) 
if sz[i] <sz[j]

*/


