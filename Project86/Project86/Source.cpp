string GetFullNameWithHistory(int year) {
	if (YearNameSoname.size() == 0) { //���� ������ = 0
		return "Incognito"; //������� ���������
	}
	else {
		for (const auto& i : YearNameSoname) {
			if (year < i.first) return "Incognito"; //���� ������� ��� ������ ������� ���� ���������, ������� ���������
			break; //����� ������� �� �����
		}
	}
	//�����
	string nm = "";
	string sn = "";
	vector<string> secondnames; //������ ���������� �������
	vector<string> firstnames; //������ ���������� ����
	for (const auto& i : YearNameSoname) { //��������� ���� ���������
		//� ����� ����������� ���������� sn �������� �������, ���� ��� �� ������ � ���� ������� ��� ������ ��������(� ���������)
		if (i.first <= year && i.second.Soname != "") { //���� ������� �������
			if (i.second.Soname != sn && sn != "") { //� �� �����������
				secondnames.push_back(sn);
			}
			sn = i.second.Soname; //��� �����������
		}
		if (i.first <= year && i.second.Name != "") { //�� �� ����� � ������
			if (i.second.Name != nm && nm != "") {
				firstnames.push_back(nm);
			}
			nm = i.second.Name;
		}
	}
	//�������������� ���������� � ������� ����� ���������� ������� � ����� � �������� �������
	string secnames_string = "", firstnames_string = "";
	if (secondnames.size() > 0) { //���� ������ � ��������� �� ����, ��
		secnames_string += " (" + secondnames[secondnames.size() - 1]; //������� � ������ ������, ������ � ���������� �������
		if (secondnames.size() > 1) {
			for (int i = secondnames.size() - 1; i > 0; --i) {//� �������� �������
				secnames_string += ", " + secondnames[i - 1]; // ������� � ������ ��������� �������
			}
		}
		secnames_string += ")"; //������� ������ �������
	}
	//���������� � �������
	if (firstnames.size() > 0) {
		firstnames_string += " (" + firstnames[firstnames.size() - 1];
		if (firstnames.size() > 1) {
			for (int i = firstnames.size() - 1; i > 0; --i) {
				firstnames_string += ", " + firstnames[i - 1];
			}
		}
		firstnames_string += ")";
	}
	//� ����������� �� ������� ����� � �������, ������ ��������������� ���������
	if (nm == "") return sn + secnames_string + " with unknown first name";
	else if (sn == "") return nm + firstnames_string + " with unknown last name";
	else return nm + firstnames_string + " " + sn + secnames_string;
}