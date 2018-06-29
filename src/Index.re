Random.self_init();

let message = {js|你好世界！|js};

ReactDOMRe.renderToElementWithId(<Component1 message />, "index1");

ReactDOMRe.renderToElementWithId(<Component2 />, "index2");

ReactDOMRe.renderToElementWithId(<Component3 startValue=7 />, "index3");