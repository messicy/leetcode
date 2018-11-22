using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class TreeNode {
	public int val;
	public TreeNode left;
	public TreeNode right;
	public TreeNode(int x) { val = x; }
}

public IList<IList<int>> ZigzagLevelOrder(TreeNode root)
{
		IList<IList<int>> ret = new List<IList<int>>();
		List<TreeNode> nodes = new List<TreeNode>();
		nodes.Add(root);
		int index = 0;
		bool order = true;
		while (nodes.Count != index)
		{
				IList<int> element = new List<int>();
				int i = index;
				for (; i < nodes.Count; i++)
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
