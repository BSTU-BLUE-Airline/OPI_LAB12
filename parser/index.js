const puppeteer = require('puppeteer');
const fs = require('fs');

setTimeout(async () => {
    fs.unlink('text.txt', (err)=>{
        if (err) console.log('Error');
        else console.log('Unlink file')
    });
    const browser = await puppeteer.launch({ headless: false });
    const page = await browser.newPage();
    await page.goto('https://www.bsb.by/kalkulyator-valyut');
    for (let i = 0; i < 14; i++) {
        let arr = await page.evaluate((index) => {
            let element = document.querySelectorAll('.custom-table__tbody-tr')[index].childNodes[0].innerText;
            return element;
        }, i);
        fs.appendFileSync('text.txt', arr + ' ');
        let arr1 = await page.evaluate((index) => {
            let element = document.querySelectorAll('.custom-table__tbody-tr')[index].childNodes[2].innerText;
            return element;
        }, i);
        fs.appendFileSync('text.txt', arr1 + ' ' + '\n');
        //let arr2 = await page.evaluate((index) => {
        //    let element = document.querySelectorAll('.custom-table__tbody-tr')[index].childNodes[3].innerText;
        //    return element;
        //}, i);
        //fs.appendFileSync('text.txt', arr2 + '\n');
    }
    await browser.close();
}, 100);
