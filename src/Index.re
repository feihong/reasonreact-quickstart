let message = {js|你好世界！|js};

ReactDOMRe.renderToElementWithId(<Component1 message=message />, "index1");

ReactDOMRe.renderToElementWithId(<Component2 greeting="Hello!" />, "index2");
