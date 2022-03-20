<template>
  <div :id="chartId" style="width:100%; height:500px" ref="chartId"></div>
</template>

<script>
let echarts = require('echarts/lib/echarts')
require('echarts/lib/chart/line')
require('echarts/lib/component/tooltip')
require('echarts/lib/component/title')
require('echarts/lib/component/legend')
require('echarts/lib/component/grid')

export default {
  props: {
    chartId: String
  },

  data () {
    return {
      chart: null
    }
  },

  mounted () {
    this.init()
  },

  methods: {
    init () {
      /* this.chart = echarts.init(document.getElementById(this.chartId)) */
      this.chart = echarts.init(this.$refs.chartId)

      let option = {
        xAxis: {
          type: 'category',
          data: ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
        },
        yAxis: {type: 'value'},
        series: [
          {
            data: [120, 200, 150, 80, 70, 110, 130],
            type: 'line'
          }
        ]
      }
      this.chart.setOption(option)
    }
  }
}
</script>
