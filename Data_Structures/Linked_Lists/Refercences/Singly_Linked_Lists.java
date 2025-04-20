package Data_Structures.Linked_Lists;

import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int value) {
        this.data = value;
        this.next = null;
    }
}

class LinkedList {
    private Node head;

    public void insertAtBeginning(int value) {
        Node newNode = new Node(value);
        newNode.next = head;
        head = newNode;
        System.out.println("Inserted " + value + " at the beginning of the list.");
    }

    public void insertAtEnd(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
        System.out.println("Inserted " + value + " into the list.");
    }

    public void deleteFromBeginning() {
        if (head == null) {
            System.out.println("List is empty. Nothing to delete.");
            return;
        }
        System.out.println("Deleted " + head.data + " from the beginning of the list.");
        head = head.next;
    }

    public void deleteFromEnd() {
        if (head == null) {
            System.out.println("List is empty. Nothing to delete.");
            return;
        }
        if (head.next == null) {
            System.out.println("Deleted " + head.data + " from the end of the list.");
            head = null;
            return;
        }
        Node temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }
        System.out.println("Deleted " + temp.next.data + " from the end of the list.");
        temp.next = null;
    }

    public void deleteNode(int value){
        if(head==null){
            return;
        }
        if(head.data==value){
            head=head.next;
            return;
        }

        Node temp=head,prev=null;
        while(temp!=null&&temp.data!=value){
            prev=temp;
            temp=temp.next;
        }
        if(temp==null){
            return;
        }
        prev.next=temp.next;
    }


    public void peek() {
        if (head == null) {
            System.out.println("List is empty. Nothing to peek.");
            return;
        }
        System.out.println("Front element: " + head.data);
    }

    public void displayList() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        Node temp = head;
        System.out.print("Linked List: ");
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }
}

public class Singly_Linked_Lists {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedList list = new LinkedList();
        int choice, value;

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Insert at Beginning");
            System.out.println("2. Insert at End");
            System.out.println("3. Delete from Beginning");
            System.out.println("4. Delete from End");
            System.out.println("5. Peek");
            System.out.println("6. Display List");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to insert: ");
                    value = scanner.nextInt();
                    list.insertAtBeginning(value);
                    break;
                case 2:
                    System.out.print("Enter value to insert: ");
                    value = scanner.nextInt();
                    list.insertAtEnd(value);
                    break;
                case 3:
                    list.deleteFromBeginning();
                    break;
                case 4:
                    list.deleteFromEnd();
                    break;
                case 5:
                    list.peek();
                    break;
                case 6:
                    list.displayList();
                    break;
                case 7:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice! Please enter a number between 1 and 7.");
            }
        }
    }
}
