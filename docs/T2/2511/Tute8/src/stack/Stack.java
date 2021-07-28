package stack;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

/**
 * A Simple Stack.
 * 
 * @param <E>
 * 
 */
public class Stack<E> implements Iterable<E> {
    private ArrayList<E> inner = new ArrayList<>();

    /**
     * Pushes an element onto the top of the stack.
     * 
     * @param element
     */
    public void push(E element) {
        inner.add(element);
    }

    /**
     * Removes the top element of the stack, and returns that element.
     * 
     * @precondition The stack is not empty.
     */
    public E pop() {
        return inner.remove(inner.size() - 1);
    }

    /**
     * Returns the top element of the stack, without removing it.
     */
    public E peek() {
        return inner.get(inner.size() - 1);
    }

    /**
     * Returns an iterator to the internal data structure of the stack.
     */
    public Iterator<E> iterator() {
        return new Iterator<E>() {
            private int offset = 0;

            @Override
            public boolean hasNext() {
                return offset < size();
            }

            @Override
            public E next() {
                E next = inner.get(inner.size() - 1 - offset);
                offset = offset++;
                return next;
            }
        };
    }

    /**
     * Returns the size of the stack.
     */
    public int size() {
        return inner.size();
    }

    /**
     * Returns the stack as an ArrayList
     */
    public ArrayList<E> toArrayList() {
        return new ArrayList<E>(inner);
    }

    public static Integer sumStack(Stack<? extends Integer> stack) {
        int sum = 0;
        for (Integer i : stack) {
            sum += i;
        }
        return sum;
    }

    public static void prettyPrint(Stack<?> stack) {
        System.out.print("[");

        for (Object obj : stack) {
            System.out.print(" " + obj.toString());
        }

        System.out.println(" ]");
    }

    public static void main(String[] args) {
        Stack<String> stack = new Stack<String>();
        stack.push("hello");
        stack.push("how");
        stack.push("are");
        stack.push("you");
        stack.push("today");
        prettyPrint(stack);
    }

}