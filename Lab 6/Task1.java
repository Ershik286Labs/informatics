import java.util.Scanner;

public class Task1 {
    static Scanner a = new Scanner(System.in);

    public static int gridLog(int x) {
        // Вычисляет логарифм по основанию 2
        int grid = (int) Math.ceil(Math.log(x) / Math.log(2)); // Округляем вверх
        return grid;
    }

    public static void main(String[] args) {
        int x;
        int grid = 0;
        String str = "";
        String binNumber = "";

        System.out.print("Введите число: "); // Просим ввести число
        x = a.nextInt();

        grid = gridLog(x); // Вызываем метод gridLog

        for (int i = 0; i < x; i++) {
            binNumber = Integer.toString(i, 2);
            for (int j = binNumber.length(); j < grid; j++){
                binNumber = "0" + binNumber;
            }
            str = str + " " + binNumber;
        }
        a.close();
        str = str.substring(1);
        System.out.println(str);
    }
}