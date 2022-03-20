import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import TestEchart from '@/components/TestEchart'
import EchartBar from '@/components/EchartBar'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'HelloWorld',
      component: HelloWorld
    },
    {
      path: '/test_echart',
      name: 'TestEchart',
      component: TestEchart
    },
    {
      path: '/test_echart2',
      name: 'EchartBar',
      component: EchartBar
    }
  ]
})
