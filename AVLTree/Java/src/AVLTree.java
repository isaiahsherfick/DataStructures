abstract class AVLTree<E>
{

    protected E data;
    protected AVLTree<E> left;
    protected AVLTree<E> right;
    public abstract boolean isBalanced();
    public abstract int getHeight();
    public abstract void rotateRight();
    public abstract void rotateLeft();
    public abstract void rebalance();
    public abstract AVLTree<E> insert(E data);
}

class Empty<E> extends AVLTree
{
    Empty()
    {
        this.data = null;
        this.left = null;
        this.right = null;
    }
    public boolean isBalanced()
    {
        return true;
    }
    public int getHeight()
    {
        return 0;
    }
    public void rotateRight()
    {
        //do nothing
    }
    public void rotateLeft()
    {
        //do nothing
    }
    public void rebalance()
    {
        //do nothing
    }

    public AVLTree<E> insert(E data)
    {
        return new Node<E>(data);
    }
}

class Node<E> extends AVLTree
{
    Node(E data)
    {
        this.data = data;
        this.left = new Empty<E>();
        this.right = new Empty<E>();
    }
    public boolean isBalanced()
    {
        return Math.abs(left.getHeight() - right.getHeight()) <= 1;
    }
    public int getHeight()
    {
        return 1 + Math.max(left.getHeight(), right.getHeight());
    }
    public AVLTree<E> insert(E data)
    {

    }
}

