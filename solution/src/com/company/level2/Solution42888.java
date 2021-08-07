package com.company.level2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Solution42888 {

	public String[] solution(String[] record) {

		Map<String, String> nicknameMapper = new HashMap<>();
		ArrayList<String> output = new ArrayList<>();

		for (String r : record) {
			String[] con = r.split(" ");

			// 들어오거나 닉네임을 바꿀때마다 id 에 대한 nickname mapper update
			if (con[0].equals("Enter") || con[0].equals("Change")) {
				nicknameMapper.put(con[1], con[2]);
			}

			if (con[0].equals("Enter") || con[0].equals("Leave")) {
				// output = {"Command uid", "Command2 uid2"}
				output.add(con[0] + " " + con[1]);
			}
		}

		String[] answer = new String[output.size()];

		for (int i = 0; i < output.size(); i++) {
			String out = output.get(i);
			String[] k = out.split(" ");

			String command = k[0];
			String uid = k[1];

			if (command.equals("Enter")) {
				answer[i] = nicknameMapper.get(uid) + "님이 들어왔습니다.";
			}
			else if (command.equals("Leave")) {
				answer[i] = nicknameMapper.get(uid) + "님이 나갔습니다.";
			}
		}
		return answer;
	}
}
