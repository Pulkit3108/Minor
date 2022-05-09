import java.util.ArrayList;
import java.util.List;

public class FpNode {
	String ID;
	List<FpNode> children;
	FpNode parent;
	FpNode next;
	long count;

	// ----------------------------------------------------------
	// Root Node
	public FpNode() {
		this.ID = null;
		this.count = -1;
		children = new ArrayList<FpNode>();
		next = null;
		parent = null;
	}

	// ----------------------------------------------------------
	// Non-root Node Structure
	public FpNode(String ID) {
		this.ID = ID;
		this.count = 1;
		children = new ArrayList<FpNode>();
		next = null;
		parent = null;
	}

	// ----------------------------------------------------------
	// Generate non-root node
	public FpNode(String ID, long count) {
		this.ID = ID;
		this.count = count;
		children = new ArrayList<FpNode>();
		next = null;
		parent = null;
	}

	// ----------------------------------------------------------
	// Add a Child
	public void addChild(FpNode child) {
		children.add(child);
	}

	public void addCount(int count) {
		this.count += count;
	}

	// ----------------------------------------------------------
	// Count add 1
	public void addCount() {
		this.count += 1;
	}

	// ----------------------------------------------------------
	// Setup next node
	public void NextNode(FpNode next) {
		this.next = next;
	}

	public void setParent(FpNode parent) {
		this.parent = parent;
	}

	// ----------------------------------------------------------
	// Pick pointed Child
	public FpNode pickChild(int index) {
		return children.get(index);
	}

	// ----------------------------------------------------------
	// Search Child ID and see if exist, and return the result
	public int ifChild(String ID) {
		for (int i = 0; i < children.size(); i++)
			if (children.get(i).ID.equals(ID))
				return i;
		return -1;
	}

	public String outSearch() {
		return "id: " + ID + " Count: " + count + " Target amount "
				+ children.size();
	}
}