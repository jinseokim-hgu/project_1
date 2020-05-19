make 방법
	make clean : object 파일과 main 실행파일 삭제
	make main : books.c 파일을 books.o 파일로 컴파일 한 후 main.c, books.o 파일로 main 실행파일 컴파일
	make main_debug : make main 컴파일 옵션에 -DDEBUG 추가

실행파일 실행방법
	./main

메인메뉴 설명
	메인메뉴는 총 16가지(16. debug 메뉴 포함)
	
	
	1. Create : 새로운 도서 정보를 추가
	
	2. Read : 하나의 도서 정보를 표시
	3. Update : 하나의 도서 정보를 업데이트
	4. Delete : 하나의 도서 정보를 삭제
	5. List : 모든 도서 정보 표시
	6. Search(name) : 이름을 입력 받아 그 이름이 포함된 모든 도서 정보 표시
	7. Search(writer) : 저자를 입력 받아 그 저자의 모든 도서 정보 표시
	8. Search(publisher) : 출판사를 입력 받아 그 출판사의 모든 도서 정보 표시
	9. Search(status) : 대출가능여부(가능:1, 불가능:0)를 입력 받아 입력 받은 여부와 일치하는 모든 도서 정보 표시
	10. Search(location) : 위치를 입력 받아 그 위치가 포함된 모든 도서 정보 표시
	11. Defragmentation : 도서 정보 데이터의 구멍난 부분을 메꾸는 조각모음
	12. Sort : 5가지 데이터 중 선택된 하나에 따라 오름차순으로 정렬
	13. Load : 텍스트 파일로부터 도서 정보를 로딩
	14. Save : 현재 도서 정보 데이터를 텍스트 파일로 저장
	15. Report : 입력 받은대로 현재 데이터의 수를 표시
	16. Debug : 현재 데이터가 메모리 공간에 제대로 할당이 되어 있는지를 표시
