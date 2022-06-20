
public class LinkedList {
    Node head;
    
    public void Append(int data) {
        Node node = new Node(data, null);
        if(head == null) {
            head = node;
        }
        else {
            Node n = head;
            while(n.next != null){
                n = n.next;
            }
            n.next = node;
        }
    }

    public void Add(int index, int data) {
        Node node = new Node(data, null);
        if(head == null) {
            head = node;
        }else if(index == 1){
            node.next = head;
            head = node;
        }
        else {
            Node n = head;
            for(int i = 2; i < index; i++) {
                n = n.next;
            }
            node.next = n.next;
            n.next = node;
        }
    }

    public void Delete(int index) {
        if(index == 1) {
            head = head.next;
        }else {
            Node n = head;
            Node n1 = null;
            for(int i = 2; i < index ; i++) {
                n = n.next;
            }
            n1 = n.next;
            n.next = n1.next;
        }
    }

    public void Swap(int index1, int index2){
        if(index1 == index2) {
            return;
        }
        if(index1 < index2) {
        Add(index1, single(index2));
        Delete(index2 + 1);
        Add((index2 + 1), single(index1 + 1));
        Delete(index1 + 1);
        }else {
        Add(index2, single(index1));
        Delete(index1 + 1);
        Add((index1 + 1), single(index2 + 1));
        Delete(index2 + 1);
        }
    }

    public void Reverse(){
        Node node = head;
        Node pre = null;
        Node curr = null;

        while (node != null) {
            curr = node;
            node = node.next;
            curr.next = pre;
            pre = curr;
            head = curr;
        }
    }

    public void Clear(){
        head = null;
    }

    public void Print() {
        Node node = head;

        while(node != null){
            System.out.println(node.value);
            node = node.next;
        }
        
    }

    public int single(int index) {
        if(index == 1){
            return head.value;
        }
        Node n = head;
        for(int i = 2; i < index; i++) {
            n = n.next;
        }
        return n.next.value;
    }
}