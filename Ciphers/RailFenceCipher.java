class RailFenceCipher {
	public static void main(String[] args) {
		String plain = "GeeksforGeeks ";
		String encrypted = encrypt(plain, 3);
		System.out.println(encrypted);
		String decrypted = decrypt(encrypted, 3);
		System.out.println(decrypted);
	}

	public static String encrypt(String plainText, int key) {
		int r = key;
		int c = plainText.length();
		char[][] rail = new char[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				rail[i][j] = '\n';
			}
		}
		boolean dir_up = true;
		int row = 0;
		for (int i = 0; i < c; i++) {
			rail[row][i] = plainText.charAt(i);
			if (row == 0 || row == key - 1) {
				dir_up = !dir_up;
			}
			if (dir_up) {
				row--;
			} else {
				row++;
			}
		}
		String cipherText = "";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (rail[i][j] != '\n') {
					cipherText += rail[i][j];
				}
			}
		}
		return cipherText;
	}

	public static String decrypt(String cipherText, int key) {
		int r = key;
		int c = cipherText.length();
		char[][] rail = new char[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				rail[i][j] = '\n';
			}
		}
		int row = 0;
		boolean dir_up = true;
		for (int i = 0; i < c; i++) {
			rail[row][i] = '*';
			if (row == 0 || row == key - 1) {
				dir_up = !dir_up;
			}
			if (dir_up) {
				row--;
			} else {
				row++;
			}
		}
		String result = "";
		int k = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (rail[i][j] == '*') {
					rail[i][j] = cipherText.charAt(k++);
				}
			}
		}
		row = 0;
		dir_up = true;
		for (int i = 0; i < c; i++) {
			result += rail[row][i];
			if (row == 0 || row == key - 1) {
				dir_up = !dir_up;
			}
			if (dir_up) {
				row--;
			} else {
				row++;
			}
		}
		return result;
	}
}