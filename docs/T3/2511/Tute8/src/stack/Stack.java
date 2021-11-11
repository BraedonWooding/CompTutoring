package stack;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.stream.Collector;
import java.util.stream.Collectors;

/**
 * A Simple Stack.
 * @param <E>
 * 
 */
public class Stack<E> implements Iterable<E> {
    private List<E> items = new ArrayList<>();

    /**
     * Pushes an element onto the top of the stack.
     * @param element
     */
    public void push(E element) {
        items.add(element);
    }

    /**
     * Removes the top element of the stack, and returns that element.
     * @precondition The stack is not empty.
     */
    public E pop() {
        return items.remove(items.size() - 1);
    }

    /**
     * Returns the top element of the stack, without removing it.
     */
    public E peek() {
        return items.get(items.size() - 1);
    }

    /**
     * Returns an iterator to the internal data structure of the stack.
     */
    public Iterator<E> iterator() {
        ListIterator<E> local = items.listIterator(items.size());

        // ArrayList.Iterator<E>
        return new Iterator<E>() {
            @Override
            public boolean hasNext() {
                return local.hasPrevious();
            }

            @Override
            public E next() {
                return local.previous();
            }
        };
    }

    /**
     * Returns the size of the stack.
     */
    public int size() {
        return items.size();
    }
    
    /**
     * Returns the stack as an ArrayList
     */
    public ArrayList<E> toArrayList() {
        return new ArrayList<E>(items);
    }

    public static int sumStack(Stack<? extends Integer> stack) {
        return stack.items.stream()
            .mapToInt(x -> x)
            .sum();
    }

    public static void prettyPrint(Stack<?> stack) {
        String result = "[";
        Iterator<?> it = stack.iterator();
        while (it.hasNext()) {
            result += it.next().toString();
            if (it.hasNext()) result += " ";
        }

        result += "]";
        System.out.println(result);
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