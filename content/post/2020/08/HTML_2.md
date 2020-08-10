---
title: "HTML 태그 2"
date: 2020-08-10T13:39:20+09:00
categories:
  - HTML5
tags:
  - HTML
  - HTML5
draft: false
---

&nbsp;HTML 태그들을 조금 더 알아보자.

<hr>

### **예제 1**

```html
<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1.0" />
	<title>Document</title>
</head>

<body>
	<img src="HTML_image_1-1.png" width="800" />
	<img src="HTML_image_1-1.png" width="800" height="200" />
	<img src="HTML_image_1-1.png" height="200" />
</body>

</html>
```

- `<img>` : 이미지를 삽입해주는 HTML 태그.

  - `src` : 이미지 파일의 url
  - `width` : 이미지의 가로 길이.
  - `height` : 이미지의 세로 길이.
  - `width`와 `height` 둘 중에 하나만 있다면 비율을 유지한 채로 축소된다.

### **결과**


![result](/images/2020/08/HTML_image_1-1.png)
<center><figcaption>원본 이미지</figcaption></center>

![result](/images/2020/08/HTML_image_2-1.png)
<center><figcaption>두 개의 이미지는 원본 비율에 맞게 줄여졌고, 하나의 이미지는 사용자 설정 비율에 맞춰진 것을 볼 수 있다.</figcaption></center>

<hr>

### **예제 2**

```html
<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Document</title>
</head>

<body>
	<!-- list -->
	<ul>
		<li>unordered list</li>
		<li>HTML</li>
		<li>CSS</li>
		<li>JavaScript</li>
	</ul>
	<ol>
		<li>ordered list</li>
		<li>HTML</li>
		<li>CSS</li>
		<li>JavaScript</li>
	</ol>
	<dl>
		<dt>
			<strong>HTML</strong>
		</dt>
		<dd>
			HyperText Markup Language의 약자
		</dd>
	</dl>
	<dl>
		<dt>
			<strong>CSS</strong>
		</dt>
		<dd>
			재미없어
		</dd>
	</dl>
	<!-- table -->
	<table>
		<caption>This is Caption</caption>
		<thead>
			<tr>
				<th>순서</th>
				<th>과목</th>
			</tr>
		</thead>
		<tfoot>
			<tr>
				<th>tfoot</th>
				<th>tfoot</th>
			</tr>
		</tfoot>
		<tbody>
			<tr><td>1</td><td>HTML</td></tr>
			<tr><td>2</td><td>CSS</td></tr>
			<tr><td>3</td><td>JavaScript</td></tr>
		</tbody>
	</table>
</body>

</html>
```

- `<ul> </ul>` : unordered list의 약자. 순서 없는 리스트
- `<ol> </ol>` : ordered list의 약자. 순서 있는 리스트
- `<dl> </dl>` : definition list의 약자. 정의 리스트
- `<table> </table>` : 표를 만들어주는 태그

### **결과**

![result](/images/2020/08/HTML_image_2-2.png)

<hr>

### **예제 3 - 1**

```html
<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Document</title>
</head>

<body>
	<a href="https://www.google.com/">구글로 이동</a>
	<hr>

	<iframe src="iframe.html"></iframe>
	<hr>
	<iframe src="iframe.html"></iframe>
	<hr>

</html>
```

### **예제 3 - 2 (iframe.html)**

```html
<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>iframe</title>
</head>

<body>
	화면 안에 또다른 화면
</body>

</html>
```

- `<a> </a>` : 하이퍼링크를 만들어주는 태그
- `<iframe> </iframe>` : 현재 페이지 내에 내장 윈도우를 만들어 다른 페이지를 출력해주는 태그

### **결과**

![result](/images/2020/08/HTML_image_2-3.png)
<center><figcaption> 화면 안에 또 다른 화면이 있다</figcaption></center>

<hr>

### **그 외 태그들**

- `<audio> </audio>` : 오디오를 삽입해주는 태그
- `<video> </video>` : 비디오를 삽입해주는 태그

<hr>