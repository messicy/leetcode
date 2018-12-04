using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class TreeNode
{
	public int val;
	public TreeNode left;
	public TreeNode right;
	public TreeNode(int x) { val = x; }
}

public IList<IList<int>> ZigzagLevelOrder(TreeNode root)
{
	IList<IList<int>> ret = new List<IList<int>>();

	if (null == root) return ret;

	List<TreeNode> nodes = new List<TreeNode>();
	nodes.Add(root);
	int index = 0;
	bool order = true;
	while (nodes.Count != index)
	{
		IList<int> element = new List<int>();
		int i = index;
		int count = nodes.Count;
		for (; i < count; i++)
		{
			element.Add(nodes[i].val);
			if (nodes[i].left != null)
			{
				nodes.Add(nodes[i].left);
			}

			if (nodes[i].right != null)
			{
				nodes.Add(nodes[i].right);
			}
		}

		index = i;

		if (!order)
		{
			element = element.Reverse().ToList();
		}

		order = !order;
		ret.Add(element);
	}

	return ret;
}

public int MajorityElement(int[] nums)
{
	if (nums.Length == 1)
	{
		return nums[0];
	}
	Dictionary<int, int> record = new Dictionary<int, int>();
	foreach (var num in nums)
	{
		if (record.ContainsKey(num))
		{
			record[num]++;
			if (record[num] > nums.Length / 2)
			{
				return num;
			}
		}
		else
		{
			record.Add(num, 1);
		}
	}
	return 0;
}

private List<int> sorted = new List<int>();

public void Inorder(TreeNode root)
{
	if (null != root.left)
	{
		Inorder(root.left);
	}

	sorted.Add(root.val);

	if (null != root.right)
	{
		Inorder(root.right);
	}
}

public int MinDiffInBST(TreeNode root)
{
	int min = int.MaxValue;

	Inorder(root);

	for (int i = 0; i < sorted.Count - 1; i++)
	{
		int t = sorted[i + 1] - sorted[i];
		if (t < min)
		{
			min = t;
		}
	}
	return min;
}

public int[] NextGreaterElement(int[] findNums, int[] nums) {
        Dictionary<int, int> indexDict = new Dictionary<int, int>();
		Stack<int> sortedNum = new Stack<int>();
		Stack<int> temp = new Stack<int>();
		for (int i = 0; i < nums.Length; i++)
		{
			while (sortedNum.Count != 0 && sortedNum.Peek() < nums[i])
			{
				int num = sortedNum.Pop();
				indexDict.Add(num, nums[i]);
				temp.Push(num);
			}

			while (temp.Count != 0)
			{
				sortedNum.Push(temp.Pop());
			}
		}

		List<int> ret = new List<int>();
		for (int i = 0; i < findNums.Length; i++)
		{
			if (indexDict.ContainsKey(findNums[i]))
			{
				ret.Add(indexDict[findNums[i]]);
			}
			else
			{
				ret.Add(-1);
			}
		}

		return ret.ToArray();
	}