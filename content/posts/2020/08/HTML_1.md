---
title: "HTML 태그 - 1"
date: 2020-08-09T12:40:48+09:00
categories:
- HTML_CSS_JAVASCRIPT
tags:
- HTML
- HTML5
- HTML tag
- HTML 태그
draft: false
---

&nbsp;HTML(HyperText Markup Language)는 웹 문서를 작성하는 태그 언어이다.
HTML 태그는 상황에 맞게 쓸 수 있는 태그 100개 이상으로 이루어져있다.

`/`는 종료 태그에 붙는 기호이다. 태그 중에는 종료 태그가 없는 경우도 있다.

<hr>

### **예제 1**
```html
<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Document</title>
</head>

<body>
	간단한 html 예제
</body>

</html>	
```
	
- `<!DOCTYPE html>` : HTML5 문서임을 브라우저에 알리는 지시어.
- `<!-- -->` : HTML에서의 주석. 여러줄에 걸쳐 사용할 수 있다.
- `<head> </head>` : 문서의 설정, 제목, 메타 태그를 적는 태그
- `<body> </body>` : 문서의 본문을 나타내는 태그

&nbsp;태그는 `tag name`과 `attribute`로 구성되어 있다. `attribute`는 name과 value로 이루어져있다.
위의 예제에서.. `<meta charset="UTF-8">`를 살펴보자.
- `tag name` = `meta`
- `attribute name` = `charset`
- `attribute value` = `UTF-8`

<hr>

### **예제 2**
```html
<!DOCTYPE html>
<html lang="en">

<head>
	<title>HTML5 tag</title>
</head>

<body>
	<h1>h1 tag</h1>
	<h2>h2 tag</h2>
	<h3>h3 tag</h3>
	<h4>h4 tag</h4>
	<h5>h5 tag</h5>
	<h6>h6 tag</h6>
	<p>This is Paragraph</p>
	<p>Meantint's Blog</p>

	first Line<br>Second Line
	<hr>Last Line

	<pre>Pre 태그는 사용자 마음대로
	위치를 
나타낼 수
		있다.
	</pre>
</body>

</html>
```

- `<title> </title>` : 페이지의 제목. 브라우저의 타이틀로 출력된다. 반드시 `head` 태그 내에서 작성되어야 함.
- `<hn> </hn>` : h1 ~ h6까지 있으며 h1이 가장 크고 h6이 가장 작다.
- `<p> </p>` : 하나의 단락을 표현하는 태그. 문단이 끝나게 되면 자동으로 빈 줄이 생성된다.
- `<hr>` : 수평선을 그어주는 태그. 밑의 결과를 보면 된다.
- `<br>` : html은 Enter키를 입력해도 개행이 되지 않으므로 태그를 이용하여 직접 개행을 시켜줘야 한다.
- `<pre> </pre` : 이 태그안에 있는 모든 텍스트들은 파일에 보이는 그대로 브라우저에 출력된다.

### **결과**

![result](/images/2020/08/HTML_image_1-1.png)

<hr>

### **예제 3**

```html
<!DOCTYPE html>
<html lang="en">

<head>
	<title>Example_3</title>
</head>

<body>
	<div style="background-color:dodgerblue">
		This is Div.<br>
		DD II VV<br>
		<span style="color:gold">This is span.
			Color is gold.</span><br>
		This is div.
	</div>
</body>

</html>
```

- `<div> </div>` : `<p>` 태그와 유사하지만 `<div>` 태그는 문단이 아닌 블록으로 묶는 태그이다.
- `<span> </span>` : 특정 텍스트만 스타일을 주거나 제어할 수 있게 하는 태그.

### **결과**

![result](/images/2020/08/HTML_image_1-2.png)

<hr